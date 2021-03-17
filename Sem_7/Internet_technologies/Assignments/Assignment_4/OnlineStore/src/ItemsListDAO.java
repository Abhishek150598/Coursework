import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

public class ItemsListDAO {
	
	public static ArrayList<Item> getItemsList(String username, String category, int netClicks, Connection con) {
		
		try {
			// Getting gender from username
			String query = "SELECT gender FROM user WHERE uname = ?";
			PreparedStatement preparedStatement = con.prepareStatement(query);
		    preparedStatement.setString(1, username);
		    ResultSet rs = preparedStatement.executeQuery();
		    rs.next();
		    String gender = rs.getString(1);
		    System.out.println("Gender is " + rs.getString(1));
		    
		    int rows = 5;
		    if(category.equals("new")) {
		    	rows += netClicks;	
		    	if(rows > 10)
		    		rows = 10;
		    }
		    else {
		    	rows -= netClicks;
		    	if(rows < 0)
		    		rows = 0;
		    }
		    // Getting list of discounted items
			query = "SELECT item_id, item_name, brand, price, category FROM item WHERE gender = ? AND category = ? LIMIT ?";
			preparedStatement = con.prepareStatement(query);
		    preparedStatement.setString(1, gender);
		    preparedStatement.setString(2, category);
		    preparedStatement.setInt(3, rows);
		    rs = preparedStatement.executeQuery();
		    
		    ArrayList<Item> items = new ArrayList<>();
		    while(rs.next()) {
		    	items.add(new Item(rs.getInt(1), rs.getString(2), rs.getString(3),rs.getDouble(4), rs.getString(5)));
		    }
		    
		    System.out.println("Getting items successful");
		    return items;
		} catch(Exception e) { 
			System.out.println(e);
			return null;
		}
	}
}