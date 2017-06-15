#define __DEBUG_ON__ 1
#if __DEBUG_ON__
  #define DBOUT cout<<__FILE__<<":"<<__LINE__
#else
  #define DBOUT 0 && cout
#endif

#define _TRCE_(_LV_) (_LV_<=__DEBUG_ON__)&&cout<<__FILE__<<":"<<__LINE__

int main(int argc, char** argv) {
  do{
    //For debug only
  }while(0);
}
