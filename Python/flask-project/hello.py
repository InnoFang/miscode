from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/')
def hello():
    return 'Welcome to Student Manager System!'

students = []

@app.route('/students', methods=['POST',])
def add_students():
    if not request.json:
        abort(400)

    item = ['id', 'name', 'age', 'birthplace', 'grade']
    for i in item:
        if not i in request.json:
            abort(400)
    
    student = {
        'id': request.json['id'],
        'name': request.json['name'],
        'age': request.json.get('age', ""),
        'birthplace': request.json.get('birthplace', ""),
        'grade': request.json['grade']
    }
    students.append(student)
    return 'success'


@app.route('/students/', methods=['PUT'])
def update_students():
    if not request.json or not 'id' in request.json:
        abort(400)
    update_id = int(request.json['id'])
    student = filter(lambda t: t['id'] == update_id, students)
    if len(student) == 0:
        abort(400)
    if not request.json:
        abort(403)

    student[0]['name'] = request.json.get('name', student[0]['name'])
    student[0]['age'] = request.json.get('age', student[0]['age'])
    student[0]['grade'] = request.json.get('grade', student[0]['grade'])
    student[0]['birthplace'] = request.json.get('birthplace', student[0]['birthplace'])

    return jsonify(student[0])


if __name__ == '__main__':
    app.run(debug=True)
    