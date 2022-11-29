#include "functions.hpp"
using namespace std;
int random_num(int x, int y){ return ((rand() % y) + x); }

string merkle_root(vector<transactions> transaction){

}

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

block_header genenerate_block(int difficulty, int nonce, vector<transactions> &transaction, vector<block_header> blockchain){
    block_header block;

    for(int i = 0; i < 100; i++){
        int transaction_id = random_num(0, transaction.size() - 1);
        block.transactions.push_back(transaction[transaction_id]);
        transaction.erase(transaction.begin() + transaction_id);        // deleting from transaction pool
    }

    block.difficulty_target = difficulty;

    // if(block_header.size() == 0) block.prev_block_hash = "-";
    // else block.prev_block_hash = block_header.block.back().block_hash;

    block.timestamp = time(0);
    block.version = "v0.1";
    block.merkel_root_hash = hash_function(merkle_root(block.transactions));
    block.nonce = nonce;
    // block.block_hash = hashing(nonce);



    return block;
}



//--- printing ---

void print_bc_info(vector<block_header> blockchain){
    ofstream out;
    out.open("bc_info.txt");

    for(int i = 1; i <= blockchain.size(); i++){

        out << "Block " << i << endl
        << "---------------------------------................." << endl
        << "Hash: " << blockchain[i].block_hash << endl
        << "Timestamp: " << /*timestampas*/ endl
        << "Version: " << blockchain[i].version << endl
        << "Merkel Root Hash: " << blockchain[i].merkel_root_hash << endl
        << "Number of transactions: " << blockchain[i].transactions.size() << endl
        << "Nonce: " << blockchain[i].nonce << endl
        << "Difficulty: " << blockchain[i].difficulty_target << endl
        << "---------------------------------" << endl << endl;
    }

    out.close();
}