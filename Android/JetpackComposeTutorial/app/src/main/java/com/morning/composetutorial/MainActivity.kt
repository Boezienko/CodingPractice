package com.morning.composetutorial

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.morning.composetutorial.ui.theme.ComposeTutorialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent { 
            MessageCard(Message("Android", "Jetpack Compose"))
        }
    }

    data class Message(val author: String, val body: String)
    
    // composable function to display text
    @Composable
    fun MessageCard(msg: Message) {
        Column {
            Text(text = msg.author)
            Text(text = msg.body)
        }
    }

    // preview composable function to show composable function in design window
    @Preview
    @Composable
    fun PreviewMessageCard(){
        MessageCard(Message("Lexi", "Hey, take a look at Jetpack Compose, it's great!"))
    }



}