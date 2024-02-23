#include <iostream>
#include <vector>


using namespace std;

struct day
{
    int weight, basic_meta;
};

day consider(const day& d1, const int t, const int after_l, const int a)
{
    int consume_energy = d1.basic_meta + a;
    int diff_weight = after_l - consume_energy;
    int new_weight = d1.weight + diff_weight;
    int diff_basic;
    int new_basic = d1.basic_meta;
    if(abs(diff_weight)>t){

        if(diff_weight%2!=0){
            diff_basic = diff_weight/2-1;
        }else{
            diff_basic = diff_weight/2;
        }
    
        new_basic = d1.basic_meta + diff_basic;
    }

    return day{new_weight, new_basic};
}

void print1(const int weight, const int basic_meta)
{
    if(basic_meta<=0||weight<=0)
    {
        cout<<"Danger Diet"<<'\n';
    }else
    {
        cout<<weight<<" "<<basic_meta<<'\n';
    }
}

void print2(const day& d, const int before_l)
{
    if(d.basic_meta<=0||d.weight<=0)
    {
        cout<<"Danger Diet";
    }else if(d.basic_meta<before_l)
    {
        cout<<d.weight<<" "<<d.basic_meta<<" YOYO";
    }else{
        cout<<d.weight<<" "<<d.basic_meta<<" NO";
    }
}

int main()
{
    int w,before_l,t;
    int d,after_l,a;
    vector <day> days;
    
    cin>>w>>before_l>>t;
    cin>>d>>after_l>>a;
    days.assign(d+1,{});
    days[0].weight = w;
    days[0].basic_meta = before_l;

    int new_w = w+d*(after_l-before_l-a);
    print1(new_w, before_l);

    for(int i = 0; i<d; i++)
    {
        days[i+1] = consider(days[i], t, after_l, a);
    }

    print2(days[d], before_l);
}