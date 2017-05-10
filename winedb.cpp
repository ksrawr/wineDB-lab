/*

http://www.codingfriends.com/index.php/2010/02/17/mysql-connection-example/

To compile up this program you will need to link to the mysql libraries and headers that are used within the program, e.g. mysql.h at the top of the program. To gain access to these, there is a nice mysql_config (you may need to install it via your package manager system if you do not have it already).

Here are my outputs of what is required on the command line for the g++ compiler



g++ -I/usr/include/mysql winedb.cpp -o winedb -L/usr/lib/mysql -lmysqlclient


./windb "select * from wineInfo where price > 100"

*/

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include "dbconnect.h"

using namespace std;
 
 
 
 
/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main()
{
  MYSQL *conn;    // the connection
  MYSQL_RES *res; // the results
  MYSQL_ROW row;  // the results row (line by line)
  char* sqlcmd;
  string s;
  ostringstream oss;
 
  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";   // the root user of mysql 
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"wine"; // the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);
 
  // assign the results return to the MYSQL_RES pointer
  
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     res = mysql_perform_query(conn, (char *)"select name, vintage, score, price, type from wineInfo");
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vitange  Rating  Price  Type
      * */
     cout << left << setw(30) <<"Wine Name" <<
                        left << setw(15) << "Vintage" <<
             left << setw(15) << "Rating" <<
             left << setw(15) << "Price"  <<
             left << setw(15) << "Type"
   << endl;
  
  while ((row = mysql_fetch_row(res)) !=NULL)
  {
   cout << setw(32) << left << row[0] << setfill(' ') // coulumn (field) #1 - Wine Name
     << setw(15) << row[1] << setfill(' ') // field #2 - Vintage
     << setw(15) << row[2] << setfill(' ') // field #3 - Rating
    << setw(13) << row[3] << setfill(' ') // field #4 - Price
    << setw(10) << row[4] << setfill(' ') // field #5 - Wine type
    << endl; // field #7 - UPC
  }
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;
}
