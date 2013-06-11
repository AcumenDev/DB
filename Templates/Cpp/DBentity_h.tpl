#ifndef DBENTITY[[DB_NAME]]_H
#define DBENTITY[[DB_NAME]]_H

[[INCLUDE_BLOCK]]

class DBEntity[[DB_NAME]] {
public:
    DBEntity[[DB_NAME]](std::string path,  std::string password);
    virtual ~DBEntity[[DB_NAME]]();

	[[LOGIC_VAR_BLOCK]]
	
protected:
private:
    sqlite3*  _Db;
    int status;
};

#endif // DBENTITY[[DB_NAME]]_H
