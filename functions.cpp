#include "functions.hpp"
using namespace std;
int random_num(int x, int y){ return ((rand() % y) + x); }

// string merkle_root(vector<transactions> transaction){

// }

vector<users> generate_users(int size){
    vector<users> user;

    for(int i = 0; i < size; i++){
        users new_user;
        new_user.name = "User_" + to_string(i);
        new_user.public_key = hash_function(new_user.name);
        new_user.balance = random_num(100, 1000000);
        user.push_back(new_user);
    }
    return user;
}


vector<transactions> generate_transactions(int size, vector<users>users){
    vector<transactions> transaction;

    for(int i = 0; i < size; i++){
        transactions new_transaction;
        int sender_id = random_num(0, 999);
        new_transaction.sender_public_key = users[sender_id].public_key;
        new_transaction.recipient_public_key = users[random_num(0, 999)].public_key;

        while(new_transaction.sender_public_key == new_transaction.recipient_public_key){
            new_transaction.recipient_public_key = users[random_num(0, 999)].public_key;
        }
        new_transaction.total = users[sender_id].balance / 10;

        new_transaction.transaction_id_hash = hash_function(new_transaction.sender_public_key + new_transaction.recipient_public_key + to_string(new_transaction.total));

        transaction.push_back(new_transaction);
    }
    return transaction;
}

block_header generate_block(int difficulty, int nonce, vector<transactions> &transaction, int blocknum){
    block_header block;

    //for v0.1
    string all_transactions = "";

    for(int i = 0; i < 100; i++){
        int transaction_id = random_num(0, transaction.size() - 1);
        block.transactions.push_back(transaction[transaction_id]);
        all_transactions += block.transactions.back().transaction_id_hash;
        transaction.erase(transaction.begin() + transaction_id);        // deleting from transaction pool
    }

    block.difficulty_target = difficulty;

    if(blocknum == 0) block.prev_block_hash = "-";
    else block.prev_block_hash = block.block_hash;

    block.timestamp = time(0);
    block.version = "v0.2";

    block.merkel_root_hash = hash_function(all_transactions); //hashing(merkle_root(block.transactions));
    block.nonce = nonce;
    block.block_hash = hash_function(to_string(nonce));

    

    return block;
}

//--- printing ---

void print_bc_info(vector<block_header> blockchain, int j){
    ofstream out;
    out.open("bc_info.txt", fstream::app);

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    // for(int i = 1; i <= j; i++){
        out << "Block " << j + 1 << ": " << endl
        << endl
        << "Hash: " << blockchain.back().block_hash << endl
        << "Timestamp: " << std::ctime(&end_time)
        << "Version: " << blockchain.back().version << endl
        << "Merkel Root Hash: " << blockchain.back().merkel_root_hash << endl
        << "Number of transactions: " << blockchain.back().transactions.size() << endl
        << "Nonce: " << blockchain.back().nonce << endl
        << "Difficulty: " << blockchain.back().difficulty_target << endl
        << "---------------------------------" << endl << endl;
    // }
    
    out.close();
}