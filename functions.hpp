#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include <string>
#include <time.h>
#include <chrono>

#include "includes/hash.hpp"


using namespace std;

class users{
    public:
        string name;
        string public_key;
        int balance;
};

class transactions{
    public:
        string transaction_id_hash;
        string sender_public_key;
        string recipient_public_key;
        int total;
};

class block_header{
    public:     // header
        int difficulty_target = 0;
        string prev_block_hash = "";
        time_t timestamp = 0;
        string version = "";
        string merkel_root_hash = "";
        unsigned int nonce = 0;
        vector<transactions> transactions;
        string block_hash;      // hash of this block
};

int random_num(int, int);

vector<users> generate_users(int);

vector<transactions> generate_transactions(int, vector<users>);

block_header genenerate_block(int, int, vector<transactions> &, vector<block_header>);

void print_bc_info(vector<block_header>);





#endif