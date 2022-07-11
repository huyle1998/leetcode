#include <iostream>
#include <vector>

void swap(int& x, int& y);
void bubble_sort(std::vector<int>& V, bool& is_increase);

int main(int argc, char** argv)
{
	std::vector<int> Vector = { 9, 10, 4, 6, 12, 90, 7 };
	bool is_increase = false;
	bubble_sort(Vector, is_increase);
	for (int i : Vector)
	{
		std::cout << "i: " << i << std::endl;
	}
}

void bubble_sort(std::vector<int>& V, bool& is_increase)
{
	for (int i = 0; i < V.size() - 1; i++)
	{
		for (int j = 0; j < V.size() - i - 1; j++)
		{
			if (true == is_increase && V[j] > V[j + 1])
			{
				swap(V[j], V[j + 1]);
			}
			if (false == is_increase && V[j] < V[j + 1])
			{
				swap(V[j], V[j + 1]);
			}

		}
	}
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}