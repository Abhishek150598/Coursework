import java.sql.*;

public class RegisterDAO {
	public static void register(String username, String password, String gender, Connection con) {
		try {
			String query = "INSERT INTO user VALUES(?, ?, ?)";
			PreparedStatement preparedStatement = con.prepareStatement(query);
		    preparedStatement.setString(1, username);
		    preparedStatement.setString(2, password);
		    preparedStatement.setString(3, gender);
		    preparedStatement.executeUpdate();
		    System.out.println("Registration successful");
		    
		} catch(Exception e) { System.out.println(e);}
	}
}
