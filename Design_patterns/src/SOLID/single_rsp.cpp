#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Journal
{
    string m_sTitle;
    std::vector<string> m_sEntries;

    Journal(const string &title):m_sTitle(title){}

    void addEntry(const string &entry)
    {
	static int count = 1;
	m_sEntries.push_back(lexical_cast<string>(count++) + ":" + entry);
    }

    void print()
    {
	for(auto ent:m_sEntries)
	    cout << ent << "\n";
    }
};

struct FileSystem
{
    static void save(const Journal &journal, const string &filename)
    {
	ofstream ofs(filename);
	for(auto val: journal.m_sEntries)
	{
	    ofs << val << endl;
	}
    }
};


int main()
{
    Journal journal{"Diary"};

    journal.addEntry("I ate dinner");
    journal.addEntry("I took out");

    FileSystem filesystem;
    filesystem.save(journal, "journal.txt");
    
    journal.print();
    return 0;
}
