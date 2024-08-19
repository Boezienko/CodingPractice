package com.morning.composetutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.morning.composetutorial.ui.theme.ComposeTutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent { 
            MessageCard(Message("Boe", "This is my first android application using Jetpack Compose"))
        }
    }

    data class Message(val author: String, val body: String)
    
    // composable function to display text
    @Composable
    fun MessageCard(msg: Message) {
        // putting everything in a row so it the elements are grouped together horizontally
        // adding padding around the elements in the row
        Row(modifier = Modifier.padding(all = 8.dp)){
            // adding a picture on the message card
            Image(
                painter = painterResource(R.drawable.profile_picture),
                contentDescription = "Contact profile picture",
                modifier = Modifier
                    // set image size to 40 dp
                    .size(40.dp)
                    // clip (crop) the image to be shaped like a circle
                    .clip(CircleShape)
            )

            // add a horizontal space between the image and column
            Spacer(modifier = Modifier.width(8.dp))

            Column {
                Text(text = msg.author)
                // add a verticle space between the author and message
                Spacer(modifier = Modifier.height(4.dp))
                Text(text = msg.body)
            }
        }
    }

    // preview composable function to show composable function in design window
    @Preview
    @Composable
    fun PreviewMessageCard(){
        MessageCard(Message("Lexi", "Hey, take a look at Jetpack Compose, it's great!"))
    }



}