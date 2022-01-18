// only accepts cards having upto 16 digits of card number.
#include<bits/stdc++.h>
using namespace std;

vector <int> doubltIt (vector <int> &num)
{
    int n= num.size();
    for(int i=1;i<n;i=i+2)
    {
        num[i] = num[i]*2;
    }
    return num;
}
int double_to_single(int num)
{
    int sum=0;
    while(num>0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}
vector <int> check_for_double(vector <int> &num)
{
    int n = num.size();
    for(int i=1;i<n;i=i+2)
    {
        if(num[i] > 9)
        {
            num[i] = double_to_single(num[i]);
        }
    }
    return num;
}
int find_sum(vector <int> &num, int k)
{
    int n = num.size();
    int sum = 0;
    for(int i = k; i < n;i=i+2)
    {
        sum = sum + num[i];      
    }
    return sum;
}
void cardCompany(vector<int> &card)
{
    if(card[0] == 4) cout<<"Visa Inc."<<endl;
    else if(card[0] == 5) cout<<"Master Cards"<<endl;
    else if(card[0] == 6) cout<<"Discover Cards"<<endl;
    else if(card[0] == 3 && card[1] == 7 ) cout<<"American Express"<<endl;
    else cout<<"Unknown"<<endl;
}
int main()
{
    vector<int> card;
    long long int cardno;
    cout<<"CARD NO: ";
    cin>>cardno;
    
    while(cardno > 0)
    {     
        card.push_back(cardno % 10);
        cardno = cardno / 10;
    }
    int n = card.size();
    if(n<13 || n>16)
    {
        cout<<"Invalid Card!! Try Again"<<endl;
        return 0;
    }
    vector<int> cardProvider;
    cardProvider.push_back(card[n-1]);
    cardProvider.push_back(card[n-2]);
    card = doubltIt(card);
    card = check_for_double(card);
    int oddsum = find_sum(card,1);
    int evensum = find_sum(card,0);
    int resultant_Sum = oddsum + evensum;

    if(resultant_Sum % 10 == 0)
    {
        cout<<"Card Provider Company: ";
        cardCompany(cardProvider);
        cout<<"Status: Valid"<<endl;
    }
    else{
        cout<<"Try Again!! Invalid Card:("<<endl;
    }
    return 0;
}
