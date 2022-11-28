#include "functions.hpp"

int random_num(int x, int y){ return ((rand() % y) + x); }

vector<users> generate_users(int size){
    vector<users> users;

    for(int i = 0; i < size; i++){
        users new_user;
        new_user.name = "Vartotojas_" + to_string(i);
        new_user.public_key = hash_function(new_user.name);
        new_user.balance = random_num(100, 1000000);
        users.push_back(new_user);
    }
    return users;
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