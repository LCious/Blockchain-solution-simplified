#include "functions.hpp"
using namespace std;

int main(){

    vector<users> users = generate_users(1000);
    vector<transactions> transactions = generate_transactions(10000, users);


    //tst
    cout << users[555].name << endl
    << users[555].public_key << endl
    << users[555].balance << endl << endl;
   
    cout <<"Hash transaction id: "<< transactions[8888].transaction_id_hash << endl
    << "Transaction public key: "<<transactions[8888].sender_public_key << endl
    << "Recipient public key: "<<transactions[8888].recipient_public_key << endl
    << "Total transactions: "<<transactions[8888].total << endl;

    vector<block_header> blocks;
    // vector blockchain;
    
    int difficulty_target = 1;

    print_bc_info(blockchain);
}