#include "functions.hpp"
using namespace std;

int main(){

    vector<users> users = generate_users(1000);
    vector<transactions> transactions = generate_transactions(10000, users);


    //tst
    // cout << vartotojai[555].name << " "
    // << vartotojai[555].public_key << " "
    // << vartotojai[555].balance << endl;

    // cout << transakcijos[8888].transaction_id_hash << " "
    // << transakcijos[8888].sender_public_key << " "
    // << transakcijos[8888].recipient_public_key << " "
    // << transakcijos[8888].total << endl;

}