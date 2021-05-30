#include "feedback.h"

Feedback::Feedback()
{
	time(&this->rawtime);
	review = '\0';
	buyer = nullptr;
}    

Feedback::Feedback(const Feedback & other)
{
	this->review = review;
	this->buyer = other.buyer;
	this->rawtime = other.rawtime;
} 

Feedback::Feedback(Feedback && other)
{
	this->review = other.review;
	other.review = nullptr;
	this->buyer = other.buyer;
	other.buyer = nullptr;
	this->rawtime = other.rawtime;
} 


const string& Feedback::getReview()const
{
	return review;
}
// returns the buyer that gives the feedback
Buyer * Feedback::getBuyer()const 
{
	return this->buyer;
}

void Feedback::getime()const 
{
	cout <<"Feedback time: " << rawtime << endl;
}
//func that sets the review
bool Feedback::setReview(const string& review)
{
	this->review = review;
	return true;
}
//func that sets pointer of the buyer that gives the feedback
void Feedback::setBuyer(Buyer * buyer)
{
	this->buyer = buyer;
}

