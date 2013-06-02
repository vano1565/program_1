#include <conio.h>
#include <iostream>

using namespace std;

int *a, i, k, j, n;

int add() {
	a = (int*)malloc(0);
	i = 0;
	k = 1;
	n = 0;
	for(;;) {
    cout<<"1 - new element, else - exit"<<endl;
    cin>>j;
    if(j == 1) {             /// adding next element
      a = (int*)realloc(a, ++n*sizeof(int));
      a[i] = k;
      ++i;
      ++k;
    }
    else {
      return 0;
    }
  }
}

void main() {
	int m;
	add();
	cout<<"Tree: "<<endl;
	cout<<"Root of the tree - a[0] = "<<a[0]<<endl;
	m = 0;
	for(i = 1; i < k - 1; i++) {              /// print tree
    if(i%2 == 0)
      m += 1;
    if(i%2 != 0)
			cout<<"Left son of node a ["<<i - m<<"] = "<<a[i]<<endl;
		if(i%2 == 0)
			cout<<"Right son of node a ["<<i - m<<"] = "<<a[i]<<endl;
  }
  _getch();
}