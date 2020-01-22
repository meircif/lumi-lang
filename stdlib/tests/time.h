#ifndef LUMI_STDLIBS_MOCK_TIME_H_INCLUDED_
#define LUMI_STDLIBS_MOCK_TIME_H_INCLUDED_

/* Mock implementation of time.h to test Lumi "time" module. */


#define CLOCKS_PER_SEC 100

#ifndef _TIME_T_DEFINED
typedef int time_t;
#endif

typedef struct tm {
   int tm_sec;
   int tm_min;
   int tm_hour;
   int tm_mday;
   int tm_mon;
   int tm_year;
   int tm_wday;
   int tm_yday;
   int tm_isdst;
} tm_t;

int time_value;
tm_t tm = {43, 54, 21, 28, 11, 118, 5, 321, 1};


int clock() {
  return 12300;
}

time_t time(time_t* timer) {
  return time_value;
}

char* ctime(time_t* timer) {
  if (*timer == time_value) {
    return "good";
  }
  return "bad";
}

int difftime(time_t timer1, time_t timer2) {
  return timer2 - timer1;
}

char* asctime(tm_t* t) {
  if (t->tm_sec == 43 &&
      t->tm_min == 54 &&
      t->tm_hour == 21 &&
      t->tm_mday == 28 &&
      t->tm_mon == 11 &&
      t->tm_year == 118 &&
      t->tm_wday == 5 &&
      t->tm_yday == 321 &&
      t->tm_isdst == 1) {
    return "good";
  }
  return "bad";
}

time_t mktime(tm_t* t) {
  if (t->tm_sec == 43 &&
      t->tm_min == 54 &&
      t->tm_hour == 21 &&
      t->tm_mday == 28 &&
      t->tm_mon == 11 &&
      t->tm_year == 118 &&
      t->tm_wday == 5 &&
      t->tm_yday == 321 &&
      t->tm_isdst == 1) {
    return time_value;
  }
  return 0;
}

size_t strftime(char* target, size_t maxsize, char* format, tm_t* t) {
  if (t->tm_sec == 43 &&
      t->tm_min == 54 &&
      t->tm_hour == 21 &&
      t->tm_mday == 28 &&
      t->tm_mon == 11 &&
      t->tm_year == 118 &&
      t->tm_wday == 5 &&
      t->tm_yday == 321 &&
      t->tm_isdst == 1 &&
      maxsize == 256 &&
      format[0] == 'A' &&
      format[1] == 'B' &&
      format[2] == '\0') {
    target[0] = 'O';
    target[1] = 'K';
    target[2] = '\0';
    return 2;
  }
  return 0;
}

tm_t* gmtime(time_t* timer) {
  tm.tm_hour = 21;
  if (*timer == time_value) {
    return &tm;
  }
  return NULL;
}

tm_t* localtime(time_t* timer) {
  tm.tm_hour = 18;
  if (*timer == time_value) {
    return &tm;
  }
  return NULL;
}


#endif  /*LUMI_STDLIBS_MOCK_TIME_H_INCLUDED_*/
