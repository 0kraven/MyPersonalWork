package com.example.myapplication;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize UI elements
        EditText usernameInput = findViewById(R.id.usernameInput);
        EditText passwordInput = findViewById(R.id.passwordInput);
        Button loginButton = findViewById(R.id.loginButton);
        Button facebookLogin = findViewById(R.id.facebookLogin);
        TextView forgotPassword = findViewById(R.id.forgotPassword);

        // Set up Login button click listener
        loginButton.setOnClickListener(v -> {
            String username = usernameInput.getText().toString().trim();
            String password = passwordInput.getText().toString().trim();

            if (username.isEmpty() || password.isEmpty()) {
                // Show a toast if fields are empty
                Toast.makeText(MainActivity.this, "Please fill in both fields", Toast.LENGTH_SHORT).show();
            } else {
                // Mock login validation
                if (username.equals("testuser") && password.equals("password")) {
                    Toast.makeText(MainActivity.this, "Login successful!", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(MainActivity.this, "Invalid username or password", Toast.LENGTH_SHORT).show();
                }
            }
        });

        // Set up Facebook login button click listener
        facebookLogin.setOnClickListener(v ->
                Toast.makeText(MainActivity.this, "Facebook login not implemented yet", Toast.LENGTH_SHORT).show()
        );

        // Set up Forgot Password click listener
        forgotPassword.setOnClickListener(v ->
                Toast.makeText(MainActivity.this, "Forgot password feature not implemented yet", Toast.LENGTH_SHORT).show()
        );
    }
}
