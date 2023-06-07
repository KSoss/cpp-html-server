# cpp-html-server
Basic template for C++ server using httplib and docker for future project use. Provides basic CRUD routes to provide simple text and JSON. To test these features simply run the following command:

```docker compose up```

Should you choose to run this outside a docker container and are not running a linux OS the additional command will need to be added in the dockerfile inside the api folder

```-lws2_32```

This will allow the windows socket library to fulfill the needed variables that linux already provides.

# TODO

There is no database functionallity but this is a quick template may prove useful in how to add a database

```
#include <sqlite3.h>
#include <string>

svr.Get("/getdata", [](const Request& req, Response& res) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    // Open the database
    if (sqlite3_open("my_database.db", &db) != SQLITE_OK) {
        res.set_content("Database open error", "text/plain");
        return;
    }

    // Prepare the SQL statement
    std::string sql = "SELECT * FROM Everything";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        res.set_content("SQL error", "text/plain");
        return;
    }

    // Execute the SQL statement and build the response
    std::string response;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        response += reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        response += "\n";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    res.set_content(response, "text/plain");
});