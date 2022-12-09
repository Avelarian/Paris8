import docx
from docx.oxml.shared import qn
import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()
doc = docx.Document('document-drive.docx')

xml = doc._element.xml
bookmarks = xml.split('w:bookmarkStart')

bookmarks_dictionary = {}

# Dealing with the bookmarks
for bookmark in bookmarks:
    if 'w:name' in bookmark:
        name = bookmark.split('w:name="')[1].split('"')[0]
        text = bookmark.split('w:t>')[1].split('<')[0]
        bookmarks_dictionary[name] = text
        G.add_node(name)

# Dealing with the hyperlinks
for bookmark in bookmarks:
    subtree = bookmark.split('w:hyperlink')
    for link in subtree:
        if 'w:anchor' in link:
            anchor = link.split('w:anchor="')[1].split('"')[0]
            if anchor in bookmarks_dictionary:
                parent = bookmark.split('w:name="')[1].split('"')[0]
                G.add_edge(parent, anchor)

nx.draw(G, with_labels=True)
plt.show()