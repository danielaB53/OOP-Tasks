#pragma once

class Counter
{
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);

	void increment();
	int getTotal() const;
	int getStep() const;

protected:
	int counter;
	unsigned step;
};
