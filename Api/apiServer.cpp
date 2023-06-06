#include <httplib.h>
#include <iostream>

int main(void)
{
    using namespace httplib;

    Server svr;

    svr.Get("/resource", [](const Request& req, Response& res) {
        res.set_content("Hello World.", "text/plain");
    });

    // svr.Post("/resource", [](const Request& req, Response& res) {
    //     res.set_content("Resource created successfully.", "text/plain");
    // });

    // svr.Put("/resource", [](const Request& req, Response& res) {
    //     res.set_content("Resource updated successfully.", "text/plain");
    // });

    // svr.Delete("/resource", [](const Request& req, Response& res) {
    //     res.set_content("Resource deleted successfully.", "text/plain");
    // });

    std::cout << "Server listening 8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
