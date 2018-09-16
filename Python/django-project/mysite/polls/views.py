from django.http import HttpResponse
from django.template import loader
from django.shortcuts import render
from .models import Question

# Create your views here.
# def index(request):
#     latest_question_list = Question.objects.order_by('-pub_date')[:5]
#     template = loader.get_template('polls/index.html')
#     context = {
#         'latest_question_list': latest_question_list,
#     }
#     # output = ', '.join([q.question_text for q in latest_question_list])
#     return HttpResponse(template.render(context, request))

# Use render() to re-implement the above function
def index(request):
    """The render() function takes the request object as its first 
    argument, a template name as its second argument and a dictionary 
    as its optional third argument. It returns an HttpResponse object 
    of the given template rendered with the given context."""
    latest_question_list = Question.objects.order_by('-pub_date')[:5]
    context = {'latest_question_list': latest_question_list}
    return render(request, 'polls/index.html', context)

def detail(request, question_id):
    return HttpResponse("You're looking at question %s." % question_id)

def results(request, question_id):
    response = "You're looking at the results of question %s."
    return HttpResponse(response % question_id)

def vote(request, question_id):
    return HttpResponse("Your're voting on question %s." % question_id)