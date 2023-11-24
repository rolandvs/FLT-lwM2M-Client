#include "catch_amalgamated.hpp"
#include "ResOp.h"

using namespace wpp;

TEST_CASE("ResOp", "[ResOp]") {
    SECTION("Default Constructor") {
        ResOp op;
        REQUIRE(op.getFlags() == 0);

        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::NONE));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::READ)             | (op.isRead()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::WRITE)            | (op.isWrite()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::EXECUTE)          | (op.isExecute()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::DISCOVER)         | (op.isDiscover()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::DELETE)           | (op.isDelete()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::BLOCK_WRITE)      | (op.isBlockWrite()));
        REQUIRE_FALSE(op.isSupported(ResOp::TYPE::BLOCK_EXECUTE)    | (op.isBlockExecute()));
    }

    SECTION("isRead Function") {
        ResOp op(ResOp::TYPE::READ);

        REQUIRE(op.isSupported(ResOp::TYPE::READ));
        REQUIRE(op.isRead() & (op.getFlags() == 1));

        REQUIRE_FALSE(op.isWrite()      | op.isExecute());
        REQUIRE_FALSE(op.isDiscover()   | op.isDelete());
        REQUIRE_FALSE(op.isBlockWrite() | op.isBlockExecute());
    }

    SECTION("isWrite(WRITE_UPD) Function") {
        ResOp op(ResOp::TYPE::WRITE_UPD);

        REQUIRE(op.isSupported(ResOp::TYPE::WRITE_UPD));
        REQUIRE(op.isWrite() & (op.getFlags() == 2));

        REQUIRE_FALSE((op.getFlags() == 4) | (op.getFlags() == 8));
    }
    SECTION("isWrite(WRITE_REPLACE_RES) Function") {
        ResOp op(ResOp::TYPE::WRITE_REPLACE_RES);

        REQUIRE(op.isSupported(ResOp::TYPE::WRITE_REPLACE_RES));
        REQUIRE(op.isWrite() & (op.getFlags() == 4));

        REQUIRE_FALSE((op.getFlags() == 2) | (op.getFlags() == 8));
    }
    SECTION("isWrite(WRITE_REPLACE_INST) Function") {
        ResOp op(ResOp::TYPE::WRITE_REPLACE_INST);

        REQUIRE(op.isSupported(ResOp::TYPE::WRITE_REPLACE_INST));
        REQUIRE(op.isWrite() & (op.getFlags() == 8));

        REQUIRE_FALSE((op.getFlags() == 2) | (op.getFlags() == 4));
    }

    SECTION("isWrite Function") {
        ResOp op(ResOp::TYPE::WRITE);

        REQUIRE(op.isSupported(ResOp::TYPE::WRITE));
        REQUIRE(op.isWrite() & (op.getFlags() == 14));

        REQUIRE_FALSE((op.getFlags() == 2)  | (op.getFlags() == 8));
        REQUIRE_FALSE(op.isRead()           | op.isExecute());
        REQUIRE_FALSE(op.isDiscover()       | op.isDelete());
        REQUIRE_FALSE(op.isBlockWrite()     | op.isBlockExecute());
    }
    SECTION("isExecute Function") {
        ResOp op(ResOp::TYPE::EXECUTE);

        REQUIRE(op.isSupported(ResOp::TYPE::EXECUTE));
        REQUIRE(op.isExecute() & (op.getFlags() == 16));

        REQUIRE_FALSE(op.isRead()       | op.isWrite());
        REQUIRE_FALSE(op.isDiscover()   | op.isDelete());
        REQUIRE_FALSE(op.isBlockWrite() | op.isBlockExecute());
    }
    SECTION("isDiscover Function") {
        ResOp op(ResOp::TYPE::DISCOVER);

        REQUIRE(op.isSupported(ResOp::TYPE::DISCOVER));
        REQUIRE(op.isDiscover() & (op.getFlags() == 32));

        REQUIRE_FALSE(op.isRead()       | op.isWrite() );
        REQUIRE_FALSE(op.isExecute()    | op.isDelete());
        REQUIRE_FALSE(op.isBlockWrite() | op.isBlockExecute());
    }
    SECTION("isDelete Function") {
        ResOp op(ResOp::TYPE::DELETE);

        REQUIRE(op.isSupported(ResOp::TYPE::DELETE));
        REQUIRE(op.isDelete() & (op.getFlags() == 64));

        REQUIRE_FALSE(op.isRead()       | op.isWrite());
        REQUIRE_FALSE(op.isExecute()    | op.isDiscover());
        REQUIRE_FALSE(op.isBlockWrite() | op.isBlockExecute());
    }
   SECTION("isBlockWrite Function") {
        ResOp op(ResOp::TYPE::BLOCK_WRITE);

        REQUIRE(op.isSupported(ResOp::TYPE::BLOCK_WRITE));
        REQUIRE(op.isBlockWrite() & (op.getFlags() == 128));

        REQUIRE_FALSE(op.isRead()       | op.isWrite());
        REQUIRE_FALSE(op.isExecute()    | op.isDiscover());
        REQUIRE_FALSE(op.isDelete()     | op.isBlockExecute());
    }
   SECTION("isBlockExecute Function") {
        ResOp op(ResOp::TYPE::BLOCK_EXECUTE);

        REQUIRE(op.isSupported(ResOp::TYPE::BLOCK_EXECUTE));
        REQUIRE(op.isBlockExecute() & (op.getFlags() == 256));

        REQUIRE_FALSE(op.isRead()       | op.isWrite());
        REQUIRE_FALSE(op.isExecute()    | op.isDiscover());
        REQUIRE_FALSE(op.isDelete()     | op.isBlockWrite());
    }

    SECTION("EXECUTE|WRITE Function") {
        ResOp op(ResOp::TYPE::EXECUTE | ResOp::TYPE::WRITE);

        REQUIRE(op.isWrite() & op.isExecute());
        REQUIRE(op.getFlags() == 30);
    }
    SECTION("READ|WRITE_REPLACE_RES Function") {
        ResOp op(ResOp::TYPE::READ | ResOp::TYPE::WRITE_REPLACE_RES);

        REQUIRE(op.isRead() & op.isWrite());
        REQUIRE(op.getFlags() == 5);
    }
    SECTION("DISCOVER|BLOCK_EXECUTE Function") {
        ResOp op(ResOp::TYPE::DISCOVER | ResOp::TYPE::BLOCK_EXECUTE);

        REQUIRE(op.isDiscover() & op.isBlockExecute());
        REQUIRE(op.getFlags() == 288);
    }
    SECTION("BLOCK_WRITE|DELETE Function") {
        ResOp op(ResOp::TYPE::BLOCK_WRITE | ResOp::TYPE::DELETE | ResOp::TYPE::WRITE_REPLACE_INST);
        
        REQUIRE(op.isBlockWrite() & op.isDelete());
        REQUIRE(op.getFlags() == 200);
    }
    SECTION("DELETE with duplicates TYPE Function") {
        ResOp op(ResOp::TYPE::DELETE | ResOp::TYPE::DELETE | ResOp::TYPE::DELETE);
                REQUIRE(op.getFlags() == 64);
    }

    SECTION("isCompatible Function") {
        ResOp op1(ResOp::TYPE::NONE        | ResOp::TYPE::WRITE);
        ResOp op2(ResOp::TYPE::WRITE       | ResOp::TYPE::EXECUTE);
        ResOp op3(ResOp::TYPE::DISCOVER    | ResOp::TYPE::DELETE);

        REQUIRE(op1.isCompatible(op2));
        REQUIRE_FALSE(op2.isCompatible(op1));
        REQUIRE_FALSE(op1.isCompatible(op3) | op2.isCompatible(op3));
    }

    SECTION("asVector Function") {
        ResOp op(
            ResOp::TYPE::NONE           |
            ResOp::TYPE::READ           |
            ResOp::TYPE::WRITE          |
            ResOp::TYPE::EXECUTE        |
            ResOp::TYPE::DISCOVER       |
            ResOp::TYPE::DELETE         |
            ResOp::TYPE::BLOCK_EXECUTE  |
            ResOp::TYPE::BLOCK_WRITE);
        std::vector<ResOp::TYPE> result = op.asVector();

        REQUIRE(result.size() == 9);
        REQUIRE(result[0] == ResOp::TYPE::READ);
        REQUIRE(result[1] == ResOp::TYPE::WRITE_UPD);
        REQUIRE(result[2] == ResOp::TYPE::WRITE_REPLACE_RES);
        REQUIRE(result[3] == ResOp::TYPE::WRITE_REPLACE_INST);
        REQUIRE(result[4] == ResOp::TYPE::EXECUTE);
        REQUIRE(result[5] == ResOp::TYPE::DISCOVER);
        REQUIRE(result[6] == ResOp::TYPE::DELETE);
        REQUIRE(result[7] == ResOp::TYPE::BLOCK_WRITE);
        REQUIRE(result[8] == ResOp::TYPE::BLOCK_EXECUTE);
    }

    SECTION("asVector2 Function") {
        ResOp op(
            ResOp::TYPE::READ               |
            ResOp::TYPE::WRITE_UPD          |
            ResOp::TYPE::WRITE_REPLACE_INST |
            ResOp::TYPE::BLOCK_WRITE);
        std::vector<ResOp::TYPE> result = op.asVector();

        REQUIRE(result.size() == 4);
        REQUIRE(result[0] == ResOp::TYPE::READ);
        REQUIRE(result[1] == ResOp::TYPE::WRITE_UPD);
        REQUIRE(result[2] == ResOp::TYPE::WRITE_REPLACE_INST);
        REQUIRE(result[3] == ResOp::TYPE::BLOCK_WRITE);
    }
}