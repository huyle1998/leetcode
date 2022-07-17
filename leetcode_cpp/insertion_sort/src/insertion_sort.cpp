#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& list, const bool& is_increase)
{
	std::vector<T> sorted_list;
	sorted_list.push_back(list[0]);
	for (int i = 1; i < list.size(); i++) {
		for (int j = 0; j < sorted_list.size(); j++) {
			if (true == is_increase) {
				if (list[i] > sorted_list[sorted_list.size() - 1])
				{
					sorted_list.push_back(list[i]);		// big-O = O(1)
					break;
				}
				else if (list[i] < sorted_list[j])
				{
					sorted_list.emplace(sorted_list.begin() + j, list[i]);
					break;
				}
			}
			else {
				if (list[i] < sorted_list[sorted_list.size() - 1]) {
					sorted_list.push_back(list[i]);		// big-O = O(1)
					break;
				}
				else if (list[i] > sorted_list[j])
				{
					sorted_list.insert(sorted_list.begin() + j, list[i]);
					break;
				}
			}
		}
	}
	list.assign(sorted_list.begin(), sorted_list.end());
}
 
void main(int argc, char** argv)
{
	std::vector<float> odev_list = { 3.2,2.4,10.1,5.2,8.2,4.7,7.7,11.4,1.6,33.22,12.141,0.99,55.56 };
	bool is_increase = false;
	insertion_sort <float>(odev_list, is_increase);
	std::cout << "odev_list after insertion_sort: ";
	for (float i : odev_list) {
		std::cout << i << " ";
	}
}
