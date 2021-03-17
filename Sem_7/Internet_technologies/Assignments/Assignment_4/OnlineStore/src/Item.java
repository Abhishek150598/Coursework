
public class Item {
	int item_id;
	String item_name;
	String brand;
	double price;
	int discount;
	String category;
	double ratings;
	
	public Item(String item_name, String brand, double price, int discount, String category, double ratings) {
		super();
		this.item_name = item_name;
		this.brand = brand;
		this.price = price;
		this.discount = discount;
		this.category = category;
		this.ratings = ratings;
	}

	public Item(int item_id, String item_name, String brand, double price, String category) {
		super();
		this.item_id = item_id;
		this.item_name = item_name;
		this.brand = brand;
		this.price = price;
		this.category = category;
	}
	
	public int getItem_id() {
		return item_id;
	}

	public void setItem_id(int item_id) {
		this.item_id = item_id;
	}

	public String getBrand() {
		return brand;
	}

	public void setBrand(String brand) {
		this.brand = brand;
	}

	public int getDiscount() {
		return discount;
	}

	public void setDiscount(int discount) {
		this.discount = discount;
	}

	public double getRatings() {
		return ratings;
	}

	public void setRatings(double ratings) {
		this.ratings = ratings;
	}

	
	public String getItem_name() {
		return item_name;
	}
	public void setItem_name(String item_name) {
		this.item_name = item_name;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public String getCategory() {
		return category;
	}
	public void setCategory(String category) {
		this.category = category;
	}
	
	
}
