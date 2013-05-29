#ifndef DBBASE_H
#define DBBASE_H
namespace DB {
///Базовый класс для подключения к бд
class DBBase {
public:
    /** Default constructor */
    DBBase() ;
    virtual  void Connect() =0;
    virtual  void  Close()=0;

    /** Default destructor */
    virtual ~DBBase();
protected:
private:
};
}
#endif // DBBASE_H
