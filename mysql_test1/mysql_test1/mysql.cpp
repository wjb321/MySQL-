#include<mysql.h>

#include<iostream>
using namespace std;
const char* host = "127.0.0.1";
const char* user = "root";
const char* pw = "1453521207";
const char* database_name = "wang";
const int port = 3306;

typedef struct student{
	int student_id;
	string student_name;
	string class_id;
}Student;
int main()
{
	MYSQL* con = mysql_init(NULL);
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		fprintf(stderr, "fail to connect Err yes! %s\n", mysql_error(con));
		return -1;
	}
	Student stu{23,"bingqing","class_4"};
	char sql[1024];
	sprintf_s(sql, "insert into students (student_id, student_name, class_id) values (%d, '%s', '%s')",stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());
	if (mysql_query(con, sql))
	{
		fprintf(stderr, "fail to connect Err %s..\n", mysql_error(con));
	}
	mysql_close(con);
	return 0;
}