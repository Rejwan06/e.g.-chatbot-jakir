<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Jakir Hossain Dental Clinic - Chatbot</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: #f0f2f5;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
    }
    .chat-container {
      background: white;
      width: 400px;
      height: 500px;
      border-radius: 10px;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
      display: flex;
      flex-direction: column;
      overflow: hidden;
    }
    .chat-box {
      flex: 1;
      padding: 15px;
      overflow-y: auto;
    }
    .input-box {
      display: flex;
      border-top: 1px solid #ccc;
    }
    .input-box input {
      flex: 1;
      padding: 10px;
      border: none;
    }
    .input-box button {
      padding: 10px 15px;
      background: #007bff;
      color: white;
      border: none;
      cursor: pointer;
    }
    .message {
      margin-bottom: 10px;
    }
    .user {
      text-align: right;
      color: blue;
    }
    .bot {
      text-align: left;
      color: green;
    }
  </style>
</head>
<body>
  <div class="chat-container">
    <div class="chat-box" id="chat-box">
      <div class="message bot">Hi! Welcome to Jakir Hossain Dental Clinic. How can I help you today?</div>
    </div>
    <div class="input-box">
      <input type="text" id="user-input" placeholder="Type your message...">
      <button onclick="sendMessage()">Send</button>
    </div>
  </div>

  <script>
    const chatBox = document.getElementById('chat-box');

    function sendMessage() {
      const input = document.getElementById('user-input');
      const message = input.value.trim();
      if (message === '') return;

      addMessage('user', message);
      input.value = '';

      setTimeout(() => {
        const botReply = getBotReply(message);
        addMessage('bot', botReply);
      }, 500);
    }

    function addMessage(sender, text) {
      const msg = document.createElement('div');
      msg.classList.add('message', sender);
      msg.textContent = text;
      chatBox.appendChild(msg);
      chatBox.scrollTop = chatBox.scrollHeight;
    }

    function getBotReply(input) {
      input = input.toLowerCase();
      if (input.includes('appointment')) {
        return "You can book an appointment by calling 0123456789.";
      } else if (input.includes('time') || input.includes('open')) {
        return "Our clinic is open from 9 AM to 8 PM, Saturday to Thursday.";
      } else if (input.includes('location')) {
        return "We're located at 123 Dental Street, Dhaka.";
      } else {
        return "Sorry, I didn't understand that. Please ask about appointment, time, or location.";
      }
    }
  </script>
</body>
</html>