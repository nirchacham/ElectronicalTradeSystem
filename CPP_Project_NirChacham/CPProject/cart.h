#ifndef _CART_H
#define _CART_H
#include "product.h"
#include "helper.h"

class Cart
{
private:
	vector<Product*> productsArray;
	float totalPrice;
	
public:
	Cart();
	Cart(const Cart& other);
	Cart(Cart&& other);
	~Cart();

	void showProducts();
	void addProduct(Product* product);
	friend class Buyer;
	
	unsigned int get_Physical_Num_Of_Products_In_Cart()  const;
	unsigned int get_Logical_Num_Of_Products_In_Cart()   const;
	vector<Product *> getproductsArray();
	void freeCart();

	void setProductsArray(vector<Product*> productArray);

	float getTotalPrice() const;
	void updateTotalPrice(float price);
	Product* getSpecificProduct(int serialNumber);
};


#endif // _CART_H
