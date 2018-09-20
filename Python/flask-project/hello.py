from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/')
def hello():
    return 'Welcome to Student Manager System!'

students = []

@app.route('/students/', methods=['POST',])
def add_student():
    # if not request.json:
    #     abort(400)

    # item = ['id', 'name', 'age', 'birthplace', 'grade']
    # for i in item:
    #     if not i in request.json:
    #         abort(400)
    
    student = {
        'id': request.json['id'],
        'name': request.json['name'],
        'age': request.json.get('age', ""),
        'birthplace': request.json.get('birthplace', ""),
        'grade': request.json['grade']
    }
    students.append(student)
    return 'success'


if __name__ == '__main__':
    app.run(debug=True)
    