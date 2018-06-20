import os
import re

def convert(path):
    if path.endswith('.c') and not path.endswith('.5.c'):
        os.remove(path)
        return
    if not path.endswith('.3.lm'):
        return
    newpath = path[:-4] + '4.lm'
    fpat = re.compile(r'[. ][fm]-[a-z\-]+\(')
    newinpat = re.compile(r'new (.+) in (.+)')
    varpat = re.compile(r'^var (.+) ([a-z\-]+)\((.+)\)')
    userpat = re.compile(r'^user (.+) ([a-z\-]+)\((.+)\)')
    ownerpat = re.compile(r'^owner (.+) ([a-z\-]+)\((.+)\)')
    qmnotpat = re.compile(r'not \(\? ([a-z\-.]+)\)')
    qmpat = re.compile(r' \? ([a-z\-.]+)(?![a-z\-.\(])')
    with open(path, 'r') as oldf, open(newpath, 'w') as newf:
        first = True
        for line in oldf:
            stripped = line.strip()
            ind = len(line) - len(stripped) - 1
            line = stripped
            if line.startswith('(##'):
                line = '~~~' + line[3:]
            if line.endswith('#)'):
                line = line[:-2] + '~~~'
            if line.startswith('##'):
                line = '~~~' + line[2:] + ' ~~~'
            if line.startswith('static '):
                line = 'struct ' + line[7:]
            line = line.replace('#', ';')
            line = line.replace('):(', ')->(')
            line = line.replace('TL4', 'TL5')
            line = fpat.sub(lambda m: m.group(0)[0] + m.group(0)[3:], line)
            line = newinpat.sub(
                    lambda m: m.group(2) + ' := ' + m.group(1) + '()', line)
            line = qmnotpat.sub(lambda m: 'not {}?'.format(m.group(1)), line)
            line = qmpat.sub(lambda m: ' {}?'.format(m.group(1)), line)
            line = varpat.sub(
                    lambda m: 'var {} {}(copy {})'.format(
                        m.group(1), m.group(2), m.group(3)),
                    line)
            line = userpat.sub(
                    lambda m: 'user {} {}(user {})'.format(
                        m.group(1), m.group(2), m.group(3)),
                    line)
            line = ownerpat.sub(
                    lambda m: 'owner {} {}(owner {})'.format(
                        m.group(1), m.group(2), m.group(3)),
                    line)
            if first and line.endswith('~~~'):
                newf.write(' ' * ind + line + '\nmodule tl5-compiler\n')
            else:
                if first:
                    newf.write('module tl5-compiler\n\n')
                if not line.startswith('delete '):
                    newf.write(' ' * ind + line + '\n')
            first = False
    # os.remove(path)

def main():
    for root, _, files in os.walk('.'):
        for name in files:
            convert(os.path.join(root, name))

if __name__ == '__main__':
    main()
