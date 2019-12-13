#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

  const char* short_options = "habc";

  const struct option long_options[] = {
    {"help",no_argument,NULL,'h'},
    {"akey",no_argument,NULL,'a'},
    {"bkey",no_argument,NULL,'b'},
    {"ckey",no_argument,NULL,'c'},
    {NULL,0,NULL,0}
  };
  bool help = false;
  bool akey = false;
  bool bkey = false;
  bool ckey = false;
  int rez;
  int option_index;

  while ((rez=getopt_long(argc,argv,short_options,
    long_options,&option_index))!=-1){

    switch(rez){
      case 'h': {
        help = true;
        break;
      };
      case 'a': {
        akey = true;
        break;
      };
  
      case 'b': {
        bkey = true;
        break;
      };
      case 'c': {
        ckey = true;
        break;
      };
      case '?': default: {
        printf("found unknown option\n");
        break;
      };
    };
  };
  if(help)
    printf("Arg: help\n");
  if(akey)
    printf("Arg: akey\n");
  if(bkey)
    printf("Arg: bkey\n");
  if(ckey)
    printf("Arg: ckey\n");
  return 0;
};
