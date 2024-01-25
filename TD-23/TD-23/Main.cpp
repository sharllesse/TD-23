#include <iostream>
#include <vector>
#include <algorithm>

void Exo1()
{
	int modified_int(0);

	[&]()
		{
			modified_int = 10;
		}();

	std::cout << modified_int << std::endl;

	std::cout << [&]()
	{
		modified_int = 10;
		return modified_int;
	}() << std::endl;
}

void Exo2()
{
	std::vector<int> vector_int = { 10, 2345, 21452, 13, -10, 29, -65 };

	std::sort(vector_int.begin(), vector_int.end(), std::less<int>());

	auto ordered_less = [](const auto _con)
		{
			for (auto con = _con.begin(); con != _con.end(); con++)
			{
				if (std::next(con) != _con.end())
				{
					if ((*con) > (*std::next(con)))
					{
						return false;
					}
				}
			}

			return true;
		};

	if (ordered_less(vector_int))
		std::cout << "is ordered" << std::endl;
	else
		std::cout << "is not ordered" << std::endl;
}

void Exo3()
{
	std::vector<int> vector_int = { 10, 2345, 21452, 13, -10, 29, -65 };

	auto negative_number_detector = [](std::vector<int> _v) -> bool
		{
			for (int i = 0; i < _v.size(); i++)
			{
				if (_v[i] < 0)
					return true;
			}

			return false;
		};

	if (negative_number_detector(vector_int))
	{
		std::cout << "Negative number found" << std::endl;
	}
	else
	{
		std::cout << "No negative number in the vector." << std::endl;
	}
}

void Exo4()
{
	std::vector<int> vector_int = { 10, 2345, 21452, 13, -10, 29, -65 };

	auto sort = [](std::vector<int>& _vector_int)
		{
			int temp = 0; //Temporary int to save the next number.
			//Do all vector size
			for (int i = 0; i < _vector_int.size(); i++)
			{
				//Using iterator v to modify and change the place
				//of the numbers.
				for (auto v = _vector_int.begin(); v != _vector_int.end(); v++)
				{
					//To avoid crash because if i try
					//to check the end so basically nothing
					//it crash.
					if (std::next(v) != _vector_int.end())
					{
						//Temp is equal to the next number.
						temp = (*std::next(v));

						//The actual number is checked.
						//If the actual number is upper than the next one
						//we switch them.
						if ((*v) > (*std::next(v)))
						{
							(*std::next(v)) = (*v);
							(*v) = temp;
						}
					}
				}
			}
		};

	sort(vector_int);
}

int main()
{
	Exo1();

	Exo2();

	Exo3();

	Exo4();
}