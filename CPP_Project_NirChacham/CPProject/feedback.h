
#ifndef _FEEDBACK_H
#define _FEEDBACK_H
#include "helper.h"
#include "buyer.h"


class Feedback
{
private:
	string review;
	Buyer* buyer;
	time_t rawtime;

public:
	Feedback();   
	Feedback(const Feedback& other); 
	Feedback(Feedback&& other); 

	bool setReview(const string& review);
	void setBuyer(Buyer* buyer);

	void getime() const;
	const string& getReview()const;
	Buyer* getBuyer() const;

};
#endif // _FEEDBACK_H





