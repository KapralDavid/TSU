#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class MediaItem
{
private:
    // common data members
    string title;
    int year;

public:
    // constructor
    MediaItem(int y, string t) : year(y), title(t)
    {
    }
    // virtual destructor
    virtual ~MediaItem() {

    };
    // pure virtual function
    virtual void action() const = 0;
    // virtual display function
    virtual void display(ostream &out) const
    {
        out << "Title:" << title << endl;
        out << "Year:" << year << endl;
    }
    // virtual read function
    virtual void read(istream &in)
    {
        in>>title>>year;
    }
    // overloaded < and > operators
    bool operator>(MediaItem &other)
    {
        return year > other.year;
    }
    bool operator<(MediaItem &other)
    {
        return year < other.year;
    }
};

// overloaded << and >> operators
ostream &operator<<(ostream &out, const MediaItem &obj)
{
    obj.display(out);
    return out;
}
istream &operator>>(istream &in, MediaItem &obj)
{
    obj.read(in);
    return in;
}

class Movie : public MediaItem
{
private:
    // additional data member or members
    string director;

public:
    // constructor
    Movie() : MediaItem(0, " "), director(" ")
    {
    }
    // override virtual functions
    void action() const override
    {
        cout << "Wathing..." << endl;
    }
    void display(ostream &out) const override
    {
        out << "Director: " << director << endl;
        MediaItem::display(out);
    }
    void read(istream &in) override
    {
        in>>director;
        MediaItem::read(in);
    }
};
class Book : public MediaItem
{
private:
    // additional data member or members if needed
    string author;

public:
    // constructor
    Book() : MediaItem(0, " "), author(" ")
    {
    }
    // override virtual functions
    void action() const override
    {
        cout << "Reading..." << endl;
    }
    void display(ostream &out) const override
    {
        out << "Author: " << author << endl;
        MediaItem::display(out);
    }
    void read(istream &in) override
    {
        in>>author;
        MediaItem::read(in);

    }
};
template <class T>
class Collection
{

private:
    vector<T> items;

public:
    void insert(const T &item)
    {
        items.push_back(item);
    }
    int size() const
    {
        return items.size();
    }
    T &operator[](int index)
    {
        return items[index];
    }
    const T &operator[](int index) const
    {
        return items[index];
    }
};
template <typename T>
void sortCollection(Collection<T> &collection)
{
    for (int i = 0; i < collection.size() - 1; i++)
    {
        for (int j = i + 1; j < collection.size(); j++)
        {
            if (*collection[j] < *collection[i])
            {
                T temp = collection[i];
                collection[i] = collection[j];
                collection[j] = temp;
            }
        }
    }
}
int main()
{
    // open file
    ifstream fin("list.txt");
    Collection<MediaItem *> objects;
    // read type
    string type;
    // create correct derived object
    // read object data
    // insert object into collection
    while (fin >> type)
    {
        if (type == "book")
        {
            MediaItem *obj = new Book();
            fin >> *obj;
            objects.insert(obj);
        }
        else if (type == "movie")
        {
            MediaItem *obj = new Movie();
            fin >> *obj;
            objects.insert(obj);
        }
    }

    // display objects before sorting
    for (int i = 0; i < objects.size(); i++)
    {
        cout << *objects[i] << endl;
    }
    // call polymorphic action
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->action();
    }

    // sort collection
    sortCollection(objects);
    // display objects after sorting
    for (int i = 0; i < objects.size(); i++)
    {
        cout << *objects[i] << endl;
    }
    // demonstrate [] operator
    cout << "First element: \n" << *objects[0] << endl;
    // delete dynamically
    for (int i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }
}
