#include "functions.hpp"
using namespace std;

int main(){

    ofstream out;
    out.open("bc_info.txt", fstream::trunc);    //trunc output

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

    int difficulty_target = 2;
    int i = 0;

    while(transactions.size() > 0){
        while(true){
            int diff_0_found = 0;
            unsigned int numonce = random_num(0, INT_MAX);
            string numonce_hash = hash_function(to_string(numonce));

            // cout << "Mining block " << i << endl;

            if(diff_0_found == difficulty_target){
                blocks.push_back(generate_block(difficulty_target, numonce, transactions, i));
                
                print_bc_info(blocks, i);

                i++;
            }
        }
    }
}