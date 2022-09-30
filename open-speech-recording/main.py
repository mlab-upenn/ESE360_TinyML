from flask import Flask
from flask import abort
from flask import make_response
from flask import redirect
from flask import render_template
from flask import request
from flask import session
from werkzeug.utils import secure_filename

import os
import uuid

app = Flask(__name__)

@app.route("/")
def welcome():
    session_id = request.cookies.get('session_id')
    if session_id:
        return render_template("record.html")
    else:
        return render_template("welcome.html")

@app.route("/start")
def start():
    response = make_response(redirect('/'))
    session_id = uuid.uuid4().hex
    response.set_cookie('session_id', session_id)
    return response

@app.route('/upload', methods=['POST'])
def upload():
    session_id = request.cookies.get('session_id')
    if not session_id:
        make_response('No session', 400)
    word = request.args.get('word')
    audio_data = request.data
    filename = word + '_' + session_id + uuid.uuid4().hex + '.ogg'
    secure_name = secure_filename(filename)
    with open(secure_name, 'wb') as f:
       f.write(audio_data)
    return make_response('All good')

# CSRF protection, see http://flask.pocoo.org/snippets/3/.
@app.before_request
def csrf_protect():
    if request.method == "POST":
        token = session['_csrf_token']
        if not token or token != request.args.get('_csrf_token'):
            abort(403)

def generate_csrf_token():
    if '_csrf_token' not in session:
        session['_csrf_token'] = uuid.uuid4().hex
    return session['_csrf_token']

app.jinja_env.globals['csrf_token'] = generate_csrf_token

app.secret_key = "DEPLOYING_LOCALLY_ONLY_PLACEHOLDER"

if __name__ == "__main__":
    app.run(debug=True)
