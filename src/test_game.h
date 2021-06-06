#ifndef TEST_GAME_H
#define TEST_GAME_H
#include "doctest/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include <jansson.h>

namespace TestJson {
    json_auto_t* json_read() {
        json_error_t error;
        json_t *root = json_load_file("assets/config.json", JSON_REJECT_DUPLICATES, &error);
        return root;
    }

    TEST_CASE("Check if we can load config.json under the assets dir") {
        json_auto_t* root = json_read();
        CHECK(root != nullptr);
        REQUIRE(root != nullptr);
        SUBCASE("Get string result") {
            json_auto_t* result = json_object_get(root, "result");
            CHECK(json_is_string(result) == true);
        }
        }

    }

#endif