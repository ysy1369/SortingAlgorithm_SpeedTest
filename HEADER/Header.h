#include <iostream>
#include <algorithm>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

enum TYPE	{INT =1,
			 DOUBLE,
			 RECTANGLE,
			 STRING
			};
enum TEST_CASE {RANDOM=1,
				INCREASE,
				DECREASE
				};
enum QUICK {STANDARD_RECURSIVE_QUICKSORT=1, 
			STANDARD_NON_RECURSIVE_QUICSORT,
			MEDIAN_3_RECURSIVE_QUICKSORT,
			MEDIAN_3_NON_RECURSIVE_QUICKSORT,
			STL_QUICKSORT
			};
enum MERGE {RECURSIVE_MERGE=6,
			NON_RECURSIVE_MERGE,
			NATURAL_MERGE
			};
enum INSERTION {BINARY_INSERTION=9,
				LINKED_INSERTION
				};
enum OTHER_SORT {HEAP_SORT=11,
				BUBBLE_SORT,
				SELECTION_SORT};
#define EXIT 14

#define NOT_SORTED -2
#define ERROR -1 vv
#define NOT_FOUND 0
#define CONTINUE 1




