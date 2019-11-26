#!/bin/bash
set -ev

# --< Setup >--
SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null && pwd )"

rm -rf $DIR/.test
mkdir $DIR/.test


$DIR/docs/test.sh
$DIR/TL0/test.sh
$DIR/TL1/test.sh
$DIR/TL2/test.sh
$DIR/TL3/test.sh
$DIR/TL4/test.sh
$DIR/TL5/test.sh
$DIR/lumi-command/test.sh
$DIR/stdlibs/test.sh


# --< Teardown >--
if [ ! -z "$CLEAR_TEST" ]; then
  rm -rf $DIR/.test
fi


# All tests passed
