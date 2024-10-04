// COMSC 210
// Melissa Ochoa Flores
// Movie reviews

#include <iostream>
#include <iomanip>
using namespace std;

struct ReviewNode {
    float rating;
    string comments;
    ReviewNode* next;
};

void addNodeToHead(ReviewNode*& head, float rating, const string& comments);
void addNodeToTail(ReviewNode*& head, float rating, const string& comments);
void outputReviews(ReviewNode* head);
void deleteList(ReviewNode*& head);
float calculateAverage(ReviewNode* head);

int main() {
    ReviewNode* head = nullptr;
    int choice;

    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
    cout << "    Choice: ";
    cin >> choice;

    char continueInput = 'y';
    while (continueInput == 'y' || continueInput == 'Y') {
        float rating;
        string comments;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, comments);

        if (choice == 1) {
            addNodeToHead(head, rating, comments);
        }
        else {
            addNodeToTail(head, rating, comments);
        }

        cout << "Enter another review? Y/N: ";
        cin >> continueInput;
    }

    outputReviews(head);
    deleteList(head);
    return 0;
}

void addNodeToHead(ReviewNode*& head, float rating, const string& comments) {
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
}

void addNodeToTail(ReviewNode*& head, float rating, const string& comments) {
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    }
    else {
        ReviewNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void outputReviews(ReviewNode* head) {
    if (!head) {
        cout << "No reviews available." << endl;
        return;
    }

    ReviewNode* current = head;
    int count = 1;
    float totalRating = 0.0;

    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "    > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        totalRating += current->rating;
        current = current->next;
    }

    float average = calculateAverage(head);
    cout << "    > Average: " << fixed << setprecision(5) << average << endl;
}

float calculateAverage(ReviewNode* head) {
    if (!head) return 0.0;

    float totalRating = 0.0;
    int count = 0;
    ReviewNode* current = head;

    while (current) {
        totalRating += current->rating;
        count++;
        current = current->next;
    }

    return totalRating / count;
}

void deleteList(ReviewNode*& head) {
    ReviewNode* current = head;
    while (current) {
        ReviewNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
