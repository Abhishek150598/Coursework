import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class ItemDetailsDAO {
	
	public static Item getItemDetails(int item_id, Connection con) {
		
		try {
			
			String query = "SELECT item_name, brand, price, discount, category, ratings FROM item WHERE item_id = ?";
			PreparedStatement preparedStatement = con.prepareStatement(query);
		    preparedStatement.setInt(1, item_id);
		    ResultSet rs = preparedStatement.executeQuery();
		    
		    rs.next();
		    Item item = new Item(
		    		rs.getString(1), 
		    		rs.getString(2), 
		    		rs.getDouble(3),
		    		rs.getInt(4), 
		    		rs.getString(5),
		    		rs.getDouble(6)
		    );
		    
		    System.out.println("Getting item details successful");
		    return item;
		} catch(Exception e) { 
			System.out.println(e);
			return null;
		}
	}
}