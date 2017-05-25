#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList
{
	public:
	    ArrayList();
		ArrayList(int pMax);
		virtual ~ArrayList();
		int getValue();
		int getPos();
		int getSize();
		int getMax();
		void setValue(int value);
		void goToStart();
		void goToEnd();
		void goToPos(int pos);
		void previous();
		void next();
		void append(int element);
		void insert(int element);
		int remove();
		void print();
		void clear();
		void bubbleSort();

	protected:
		int *elements;
		int max;
		int size;
		int pos;
};
#endif // ARRAYLISTN_H
