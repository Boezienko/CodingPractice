package com.morning.composetutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.border
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
            // adding theme to the message card
            ComposeTutorialTheme {
                Surface(modifier = Modifier.fillMaxSize()){
                    MessageCard(Message("Boe", "This is my first android application using Jetpack Compose"))
                }
            }
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
                    // add boarder abround profile picture that is the primary color of our theme
                    .border(1.5.dp, MaterialTheme.colorScheme.primary, CircleShape)
            )

            // add a horizontal space between the image and column
            Spacer(modifier = Modifier.width(8.dp))

            Column {
                Text(
                    text = msg.author,
                    // make the text use the secondary color in our theme
                    color = MaterialTheme.colorScheme.secondary,
                    // make the text use a particular style/font
                    style = MaterialTheme.typography.titleSmall
                )

                // add a verticle space between the author and message
                Spacer(modifier = Modifier.height(4.dp))

                // make this text element be in a shape
                Surface(shape = MaterialTheme.shapes.medium, shadowElevation = 1.dp) {
                    Text(
                        text = msg.body,
                        style = MaterialTheme.typography.bodyMedium
                    )
                }

            }
        }
    }

    // preview composable function to show composable function in design window
    @Preview
    @Composable
    fun PreviewMessageCard(){
        // adding theme to preview in design window
        ComposeTutorialTheme {
            Surface {
                MessageCard(
                    msg = Message("Lexi", "Hey, take a look at Jetpack Compose, it's great!")
                )
            }
        }
    }



}