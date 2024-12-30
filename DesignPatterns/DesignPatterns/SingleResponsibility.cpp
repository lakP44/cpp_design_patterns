#include <iostream>
#include <fstream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

// HOS ������ �̸��� ������ �����ϴ� ����ü
struct HOS_hero
{
	string name;
	vector<string> stat;

	HOS_hero(string name) : name(name) {} // ������

	// stat�� �߰��ϴ� �Լ�
	void add_stat(const string& s)
	{
		static int count = 0;
		stat.push_back(lexical_cast<string>(count++) + ": " + s);
	}

	//void save(const string& filename)
	//{
	//	ofstream file(filename);
	//	try
	//	{
	//		if (!file)
	//			throw std::exception("file open error");

	//		for (auto& e : stat)
	//			file << e << endl;

	//		cout << filename + " saved" << endl;
	//	}
	//	catch (std::exception& err)
	//	{
	//		cout << err.what() << endl;
	//		return;
	//	}
	//}
};

// ���Ӽ� ������
struct PersistenceManager
{
	// �̷��� �ϸ� HOS_hero�� save �Լ��� PersistenceManager�� �Ű���
	// �ϳ��� ����ü�� �ϳ��� å�Ӹ� �������� �ϴ� ���� SRP
	void save(const HOS_hero& HOS, const string& filename)
	{
		ofstream file(filename);
		try
		{
			if (!file)
				throw std::exception("file open error");

			for (auto& e : HOS.stat)
				file << e << endl;

			cout << filename + " saved" << endl;
		}
		catch (std::exception& err)
		{
			cout << err.what() << endl;
			return;
		}
	}
};

int main()
{
	HOS_hero hero("Abathru");

	hero.add_stat("HP: 100");
	hero.add_stat("MP: 50");
	hero.add_stat("ramen");

	// hero.save("Abathru.txt");
	PersistenceManager pm;
	pm.save(hero, "Abathru.txt");
}
