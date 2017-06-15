#define __DEBUG_ON__ 1
#if __DEBUG_ON__
  #define DBOUT cout<<__FILE__<<":"<<__LINE
#else
  #define DBOUT 0 && cout
#endif

int main(int argc, char** argv) {
  do{
    //For debug only
  }while(0);
}
