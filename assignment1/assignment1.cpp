#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

class LibraryItem
{
protected:
    int id;
    string title;
    int year;
    string creator;
    bool available;

public:
    LibraryItem(int i, string t, int y, string c) : available(true)
    {
        setId(i);
        setTitle(t);
        setYear(y);
        setCreator(c);
    }

    // virtual functions and deconstructor
    virtual ~LibraryItem() {};
    virtual void display() const = 0;
    virtual string getType() const = 0;
    virtual void saveToFile(ofstream &out) const = 0;
    virtual double calculateLateFee(int overdueDays) const = 0;

    // Getters
    int getId() const
    {
        return id;
    }
    string getTitle() const
    {
        return title;
    }
    int getYear() const
    {
        return year;
    }
    string getCreator() const
    {
        return creator;
    }
    bool getAvailable() const
    {
        return available;
    }

    // Setters
    void setId(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
            cout << "Not a valid value" << endl;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setYear(int year)
    {
        if (year >= 1450 && year <= 2026)
        {
            this->year = year;
        }
        else
            cout << "Not a valid value" << endl;
    }
    void setCreator(string creator)
    {
        this->creator = creator;
    }
    void setAvailable(bool available)
    {
        this->available = available;
    }

    // Overloading operators
    bool operator<(const LibraryItem &other) const
    {
        return year < other.year;
    }
    bool operator==(const LibraryItem &other) const
    {
        return id == other.id;
    }
    friend ostream &operator<<(ostream &out, const LibraryItem &item)
    {
        item.display();
        return out;
    }
};

class Book : public LibraryItem
{
private:
    string genre;
    int pages;

public:
    Book(int id, string title, int year, string author, int pages, string genre)
        : LibraryItem(id, title, year, author)
    {
        setPages(pages);
        setGenre(genre);
    }

    // virtual functions
    void display() const override
    {
        cout << "Book | ID: " << id
             << " | Title: " << title
             << " | Author: " << creator
             << " | Year: " << year
             << " | Pages: " << pages
             << " | Genre: " << genre
             << " | Status: " << (available ? "Available" : "Borrowed")
             << endl;
    }
    string getType() const override
    {
        return "Book";
    }
    void saveToFile(ofstream &out) const override
    {
        out << "[Book]" << endl;
        out << "ID: " << id << endl;
        out << "Title: " << title << endl;
        out << "Author: " << creator << endl;
        out << "Year: " << year << endl;
        out << "Pages: " << pages << endl;
        out << "Genre: " << genre << endl;
        out << "Status: " << (available ? "Available" : "Borrowed") << endl;
        out << "Late fee per day: 0.50 GEL\n"
            << endl;
    }
    double calculateLateFee(int overdueDays) const override
    {
        return overdueDays * 0.50;
    }

    // Pages
    int getPages() const
    {
        return pages;
    }
    void setPages(int pages)
    {
        if (pages >= 2)
        {
            this->pages = pages;
        }
    }

    // Genre
    string getGenre() const
    {
        return genre;
    }
    void setGenre(string genre)
    {
        this->genre = genre;
    }
};
class Magazine : public LibraryItem
{
private:
    int issueNumber;
    int month;

public:
    Magazine(int id, string title, int year, string author, int issueNumber, int month)
        : LibraryItem(id, title, year, author)
    {
        setIssueNumber(issueNumber);
        setMonth(month);
    }

    // virtual functions
    void display() const override
    {
        cout << "Magazine | ID: " << id
             << " | Title: " << title
             << " | Author: " << creator
             << " | Year: " << year
             << " | Issue number: " << issueNumber
             << " | Month: " << month
             << " | Status: " << (available ? "Available" : "Borrowed")
             << endl;
    }
    string getType() const override
    {
        return "Magazine";
    }
    void saveToFile(ofstream &out) const override
    {
        out << "[Magazine]" << endl;
        out << "ID: " << id << endl;
        out << "Title: " << title << endl;
        out << "Author: " << creator << endl;
        out << "Year: " << year << endl;
        out << "Issue number: " << issueNumber << endl;
        out << "Month: " << month << endl;
        out << "Status: " << (available ? "Available" : "Borrowed") << endl;
        out << "Late fee per day: 0.30 GEL\n"
            << endl;
    }
    double calculateLateFee(int overdueDays) const override
    {
        return overdueDays * 0.30;
    }

    // IssueNumber
    int getIssueNumber() const
    {
        return issueNumber;
    }
    void setIssueNumber(int issueNumber)
    {
        this->issueNumber = issueNumber;
    }
    // Month
    int getMonth() const
    {
        return month;
    }
    void setMonth(int month)
    {
        if (month > 0 && month <= 12)
            this->month = month;
    }
};
class DVD : public LibraryItem
{
private:
    int duration;
    int ageRating;

public:
    DVD(int id, string title, int year, string author, int duration, int ageRating)
        : LibraryItem(id, title, year, author)
    {
        setDuration(duration);
        setAgeRating(ageRating);
    }

    // virtual functions
    void display() const override
    {
        cout << "DVD | ID: " << id
             << " | Title: " << title
             << " | Author: " << creator
             << " | Year: " << year
             << " | Duration: " << duration
             << " | Age rating: " << ageRating
             << " | Status: " << (available ? "Available" : "Borrowed")
             << endl;
    }
    string getType() const override
    {
        return "DVD";
    }
    void saveToFile(ofstream &out) const override
    {
        out << "[DVD]" << endl;
        out << "ID: " << id << endl;
        out << "Title: " << title << endl;
        out << "Author: " << creator << endl;
        out << "Year: " << year << endl;
        out << "Duration: " << duration << endl;
        out << "Age rating: " << ageRating << endl;
        out << "Status: " << (available ? "Available" : "Borrowed") << endl;
        out << "Late fee per day: 1.00 GEL\n"
            << endl;
    }
    double calculateLateFee(int overdueDays) const override
    {
        return overdueDays * 1.00;
    }

    // Duration
    int getDuration() const
    {
        return duration;
    }
    void setDuration(int duration)
    {
        if (duration > 0)
            this->duration = duration;
    }

    // AgeRating
    int getAgeRating() const
    {
        return ageRating;
    }
    void setAgeRating(int ageRating)
    {
        if (ageRating > 0 && ageRating <= 25)
            this->ageRating = ageRating;
    }
};
class ResearchPaper : public LibraryItem
{
private:
    string doi;
    string j_c;

public:
    ResearchPaper(int id, string title, int year, string author, string doi, string j_c)
        : LibraryItem(id, title, year, author)
    {
        setDoi(doi);
        setAgeJ_C(j_c);
    }

    // virtual functions
    void display() const override
    {
        cout << "Research paper | ID: " << id
             << " | Title: " << title
             << " | Author: " << creator
             << " | Year: " << year
             << " | DOI: " << doi
             << " | Journal/conference: " << j_c
             << " | Status: " << (available ? "Available" : "Borrowed")
             << endl;
    }
    string getType() const override
    {
        return "ResearchPaper";
    }
    void saveToFile(ofstream &out) const override
    {
        out << "[Research paper]" << endl;
        out << "ID: " << id << endl;
        out << "Title: " << title << endl;
        out << "Author: " << creator << endl;
        out << "Year: " << year << endl;
        out << "DOI: " << doi << endl;
        out << "Journal/conference: " << j_c << endl;
        out << "Status: " << (available ? "Available" : "Borrowed") << endl;
        out << "Late fee per day: 0.20 GEL\n"
            << endl;
    }
    double calculateLateFee(int overdueDays) const override
    {
        return overdueDays * 0.20;
    }

    // DOI
    string getDoi() const
    {
        return doi;
    }
    void setDoi(string doi)
    {
        this->doi = doi;
    }

    // Journal_conference
    string getJ_C() const
    {
        return j_c;
    }
    void setAgeJ_C(string j_c)
    {
        this->j_c = j_c;
    }
};

class LibraryManager
{
private:
    vector<unique_ptr<LibraryItem>> items;

    bool isUniqueId(int id) const
    {
        for (const auto &item : items)
        {
            if (item->getId() == id)
                return false;
        }
        return true;
    }

public:
    void addItem(unique_ptr<LibraryItem> item)
    {
        if (!isUniqueId(item->getId()))
        {
            throw runtime_error("There is duplicate ID, item is not added!");
        }
        items.push_back(move(item));
    }

    void displayAll() const
    {
        if (items.empty())
        {
            cout << "Library is empty" << endl;
            return;
        }
        for (const auto &item : items)
        {
            item->display();
        }
    }

    LibraryItem *searchById(int id) const
    {
        for (const auto &item : items)
        {
            if (item->getId() == id)
                return item.get();
        }
        return nullptr;
    }

    void borrowItem(int id)
    {
        LibraryItem *item = searchById(id);
        if (!item)
            throw runtime_error("Item not found");
        if (!item->getAvailable())
            throw runtime_error("Item is already borrowed");
        item->setAvailable(false);
        cout << "Item borrowed successfully" << endl;
    }

    void returnItem(int id, int overdueDays)
    {
        LibraryItem *item = searchById(id);
        if (!item)
            throw runtime_error("Item not found");
        if (item->getAvailable())
            throw runtime_error("Item was not borrowed");
        item->setAvailable(true);
        double fee = item->calculateLateFee(overdueDays);
        cout << "Item returned, late fee: " << fee << " GEL" << endl;
    }

    void deleteItem(int id)
    {
        LibraryItem *target = searchById(id);
        if (!target)
            throw runtime_error("Item is not found");

        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (**it == *target)
            {
                items.erase(it);
                cout << "Item deleted" << endl;
                return;
            }
        }
    }

    void sortByTitle()
    {
        if (items.empty())
            throw runtime_error("Library is empty");

        for (int i = 0; i < items.size(); ++i)
        {
            for (int j = i + 1; j < items.size(); ++j)
            {
                if (items[i]->getTitle() > items[j]->getTitle())
                {
                    swap(items[i], items[j]);
                }
            }
        }
        cout << "Items sorted by title" << endl;
    }

    void generateReport() const
    {
        if (items.empty())
        {
            cout << "Library is empty" << endl;
            return;
        }

        cout << "Total items: " << items.size() << endl;

        int availableCount = 0, borrowedCount = 0, books = 0, magazines = 0, dvds = 0, papers = 0;

        const LibraryItem *oldest = items.front().get();
        const LibraryItem *newest = items.front().get();

        for (const auto &item : items)
        {
            item->getAvailable() ? availableCount++ : borrowedCount++;

            if (item->getType() == "Book")
                books++;
            else if (item->getType() == "Magazine")
                magazines++;
            else if (item->getType() == "DVD")
                dvds++;
            else if (item->getType() == "ResearchPaper")
                papers++;

            if (*item < *oldest)
                oldest = item.get();
            if (*newest < *item)
                newest = item.get();
        }

        cout << "Available: " << availableCount << ", Borrowed: " << borrowedCount << endl;
        cout << "Books: " << books << ", Magazines: " << magazines
             << ", DVDs: " << dvds << ", Research papers: " << papers << endl;
        cout << "Oldest item: " << *oldest;
        cout << "Newest item: " << *newest;
    }

    void saveAll(const string &filename) const
    {
        ofstream out(filename);
        if (!out)
            throw runtime_error("File open error");

        for (const auto &item : items)
        {
            item->saveToFile(out);
        }
        cout << "Saved to file" << endl;
    }

    void loadAll(const string &filename)
    {
        ifstream in(filename);
        if (!in)
            throw runtime_error("File open error");

        items.clear();
        string line;
        int loadedCount = 0;

        while (getline(in, line))
        {
            if (line.empty())
                continue;

            if (line == "[Book]")
            {
                int id, year, pages;
                string title, author, genre, status;

                getline(in, line);
                id = stoi(line.substr(4));
                getline(in, line);
                title = line.substr(7);
                getline(in, line);
                author = line.substr(8);
                getline(in, line);
                year = stoi(line.substr(6));
                getline(in, line);
                pages = stoi(line.substr(7));
                getline(in, line);
                genre = line.substr(7);
                getline(in, line);
                status = line.substr(8);

                auto book = make_unique<Book>(id, title, year, author, pages, genre);
                book->setAvailable(status == "Available");
                items.push_back(move(book));
                loadedCount++;
            }
            else if (line == "[Magazine]")
            {
                int id, year, issue, month;
                string title, author, status;

                getline(in, line);
                id = stoi(line.substr(4));
                getline(in, line);
                title = line.substr(7);
                getline(in, line);
                author = line.substr(8);
                getline(in, line);
                year = stoi(line.substr(6));
                getline(in, line);
                issue = stoi(line.substr(14));
                getline(in, line);
                month = stoi(line.substr(7));
                getline(in, line);
                status = line.substr(8);

                auto mag = make_unique<Magazine>(id, title, year, author, issue, month);
                mag->setAvailable(status == "Available");
                items.push_back(move(mag));
                loadedCount++;
            }
            else if (line == "[DVD]")
            {
                int id, year, duration, ageRating;
                string title, author, status;

                getline(in, line);
                id = stoi(line.substr(4));
                getline(in, line);
                title = line.substr(7);
                getline(in, line);
                author = line.substr(8);
                getline(in, line);
                year = stoi(line.substr(6));
                getline(in, line);
                duration = stoi(line.substr(10));
                getline(in, line);
                ageRating = stoi(line.substr(12));
                getline(in, line);
                status = line.substr(8);

                auto dvd = make_unique<DVD>(id, title, year, author, duration, ageRating);
                dvd->setAvailable(status == "Available");
                items.push_back(move(dvd));
                loadedCount++;
            }
            else if (line == "[Research paper]")
            {
                int id, year;
                string title, author, doi, journal, status;

                getline(in, line);
                id = stoi(line.substr(4));
                getline(in, line);
                title = line.substr(7);
                getline(in, line);
                author = line.substr(8);
                getline(in, line);
                year = stoi(line.substr(6));
                getline(in, line);
                doi = line.substr(5);
                getline(in, line);
                journal = line.substr(20);
                getline(in, line);
                status = line.substr(8);

                auto paper = make_unique<ResearchPaper>(id, title, year, author, doi, journal);
                paper->setAvailable(status == "Available");
                items.push_back(move(paper));
                loadedCount++;
            }
            else
            {
                continue;
            }
        }

        cout << "Successfully loaded " << loadedCount << " records" << endl;
    }
};

int main()
{
    LibraryManager manager;
    int choice;

    while (true)
    {
        cout << "\n===== Library Menu =====\n";
        cout << "1 Add Item" << endl;
        cout << "2 Display All Items" << endl;
        cout << "3 Search Item" << endl;
        cout << "4 Borrow Item" << endl;
        cout << "5 Return Item" << endl;
        cout << "6 Delete Item" << endl;
        cout << "7 Sort Items" << endl;
        cout << "8 Generate Report" << endl;
        cout << "9 Save to File" << endl;
        cout << "10 Load from File" << endl;
        cout << "0 Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                int type;
                cout << "Choose type: 1=Book, 2=Magazine, 3=DVD, 4=ResearchPaper: ";
                cin >> type;

                if (type == 1)
                {
                    int id, year, pages;
                    string title, author, genre;

                    cout << "Enter ID: ";
                    cin >> id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Title: ";
                    getline(cin, title);

                    cout << "Enter Author: ";
                    getline(cin, author);

                    cout << "Enter Year: ";
                    cin >> year;

                    cout << "Enter Pages: ";
                    cin >> pages;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Genre: ";
                    getline(cin, genre);

                    manager.addItem(make_unique<Book>(id, title, year, author, pages, genre));
                }
                else if (type == 2)
                {
                    int id, year, issue, month;
                    string title, publisher;

                    cout << "Enter ID: ";
                    cin >> id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Title: ";
                    getline(cin, title);

                    cout << "Enter Publisher: ";
                    getline(cin, publisher);

                    cout << "Enter Year: ";
                    cin >> year;

                    cout << "Enter Issue Number: ";
                    cin >> issue;

                    cout << "Enter Month: ";
                    cin >> month;

                    manager.addItem(make_unique<Magazine>(id, title, year, publisher, issue, month));
                }
                else if (type == 3)
                {
                    int id, year, duration, ageRating;
                    string title, director;

                    cout << "Enter ID: ";
                    cin >> id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Title: ";
                    getline(cin, title);

                    cout << "Enter Director: ";
                    getline(cin, director);

                    cout << "Enter Year: ";
                    cin >> year;

                    cout << "Enter Duration: ";
                    cin >> duration;

                    cout << "Enter Age Rating: ";
                    cin >> ageRating;

                    manager.addItem(make_unique<DVD>(id, title, year, director, duration, ageRating));
                }
                else if (type == 4)
                {
                    int id, year;
                    string title, author, journal, doi;

                    cout << "Enter ID: ";
                    cin >> id;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Title: ";
                    getline(cin, title);

                    cout << "Enter Author: ";
                    getline(cin, author);

                    cout << "Enter Year: ";
                    cin >> year;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter Journal/Conference: ";
                    getline(cin, journal);

                    cout << "Enter DOI: ";
                    getline(cin, doi);

                    manager.addItem(make_unique<ResearchPaper>(id, title, year, author, doi, journal));
                }
            }
            else if (choice == 2)
            {
                manager.displayAll();
            }
            else if (choice == 3)
            {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                LibraryItem *item = manager.searchById(id);
                if (item)
                    cout << *item;
                else
                    cout << "Item is not found" << endl;
            }
            else if (choice == 4)
            {
                int id;
                cout << "Enter ID to borrow: ";
                cin >> id;
                manager.borrowItem(id);
            }
            else if (choice == 5)
            {
                int id, days;
                cout << "Enter ID and overdue days: ";
                cin >> id >> days;
                manager.returnItem(id, days);
            }
            else if (choice == 6)
            {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                manager.deleteItem(id);
            }
            else if (choice == 7)
            {
                manager.sortByTitle();
            }
            else if (choice == 8)
            {
                manager.generateReport();
            }
            else if (choice == 9)
            {
                manager.saveAll("library.txt");
            }
            else if (choice == 10)
            {
                manager.loadAll("library.txt");
            }
            else if (choice == 0)
            {
                cout << "Exiting..." << endl;
                break;
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
