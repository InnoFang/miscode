/**
 * Created by InnF on 2018/4/5.
 */

import React, {Component} from 'react'
import CommentInput from './CommentInput'
import CommentList from './CommentList'

class CommentApp extends Component {

    constructor() {
        super()
        this.state = {
            comments: []
        }
    }

    componentWillMount() {
        this._loadComments()
    }

    _loadComments() {
        let comments = localStorage.getItem('comments')
        if (comments) {
            comments = JSON.parse(comments)
            this.setState({comments})
        }
    }

    _saveComments(comments) {
        localStorage.setItem('comments', JSON.stringify(comments))
    }

    handleDeleteComment(index) {
        const comments = this.state.comments
        comments.splice(index, 1)
        this.setState({comments})
        this._saveComments(comments)
    }

    handleSubmitComment(comment) {
        if (!comment) return
        if (!comment.username) return alert('Username is required.')
        if (!comment.content) return alert('Content is required.')
        const comments = this.state.comments
        this.state.comments.push(comment)
        this.setState({comments})
        this._saveComments(comments)
        // alert(`username: ${comment.username}, content: ${comment.content}`)
    }

    render() {
        return (
            <div className="wrapper">
                <CommentInput
                    onSubmit={this.handleSubmitComment.bind(this)}/>
                <CommentList
                    comments={this.state.comments}
                    onDeleteComment={this.handleDeleteComment.bind(this)}/>
            </div>
        )
    }
}

export default CommentApp