// COPYRIGHT 2024 apacicco
#include<iostream>
#include<iomanip>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

/*
	rewatched the vidoes I missed. took good notes and redid all my code. should be much better now
*/

bool is_leap_year(int leap_year) {
    if (leap_year % 400 == 0) return true;
    if (leap_year % 100 == 0) return false;
    return leap_year % 4 == 0;
}


int days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// i am not exactly sure why we need the &. It works tho. 
//determines if we went over to another month, 
// and if we go to another year, we're down to one again


void add(int& day, int& month, int& year) {
    day++;
    if (day > days_in_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;// resets
            year++;
        }
    }
}


int main() {
    char slash;// divider for dates
	char debit_or_credit_indicator;// c d or q
	double money;// amount credited or debited
    double new_balance;// initial deposit
	double current;//current balance
    double total_balance = 0; //total balance among the days
    int days = 0; // total days in which money was in the bank, and transactions were made within a month and q wasn't clicked
    int start_day; // initial day
	int	start_month;// initial month
	int start_year;// initial year
	int next_day;// self explanatory, as is below
	int next_month;
	int next_year;
	double average_balance;//final average balance
	
	cout << std::setprecision(2)
     << std::setiosflags
     (std::ios::showpoint | std::ios::fixed);
	
    cin >> start_month >> slash >> start_day >> slash >> start_year >> new_balance;

    current = new_balance;
    int current_day = start_day;
	int current_month = start_month; 
	int currY = start_year;

    while (debit_or_credit_indicator != 'q' && days < 30) {
        cin >> debit_or_credit_indicator;
		if (debit_or_credit_indicator == 'q'){
			break;
		}
		cin >> next_month >> slash >> next_day >> slash >> next_year >> money;

        if (next_year < currY || (next_year == currY && next_month < current_month) || (next_year == currY && next_month == current_month && next_day < current_day)) {
            cout << "Entries must be provided in chronological order." << endl;
            cout << next_month << "/" << next_day << "/" << next_year << " entered after " << current_month << "/" << current_day << "/" << currY << endl;
            return 0;
        }

        while (days < 30 && ((currY < next_year) || (currY == next_year && current_month < next_month) || (currY == next_year && current_month == next_month && current_day < next_day))) {
            total_balance += current;
            days++;
            add(current_day, current_month, currY);
        }

        if (debit_or_credit_indicator == 'd') {
            if (current < money) {
                cout << "Overdraft on " << next_month << "/" << next_day << "/" << next_year << ". $15 overdraft fee assessed." << endl;
				// printed here because when I tried to move it to the end, either the date or the balance would get screwed up
                money = money + 15.0;
            }
            current -= money;
        } else if (debit_or_credit_indicator == 'c') {
            current += money;
        }
    }

    if (days < 30) {
        total_balance += current;
        days++;
    }

    
    if (days > 0) {
        average_balance = total_balance / days;
    } else {
        average_balance = 0.0;
    }

    cout << days << "-day average balance (" << start_month << "/" << start_day << "/" << start_year << "-" << current_month << "/" << (days < 30 ? current_day : current_day - 1) << "/" << currY << "): $" << average_balance << endl;

    return 0;
}
