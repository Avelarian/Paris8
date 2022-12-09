FROM python:3

WORKDIR /usr/src/app

RUN pip install python-docx networkx matplotlib

COPY . .

CMD [ "python", "script.py" ]