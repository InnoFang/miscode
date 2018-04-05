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

    handleSubmitComment(comment) {
        if (!comment) return
        if (!comment.username) return alert('Username is required.')
        if (!comment.content) return alert('Content is required.')
        this.state.comments.push(comment)
        this.setState({comments: this.state.comments})
        // alert(`username: ${comment.username}, content: ${comment.content}`)
    }

    render() {
        return (
            <div className="wrapper">
                <CommentInput
                    onSubmit={this.handleSubmitComment.bind(this)}/>
                <CommentList comments={this.state.comments}/>
            </div>
        )
    }
}

export default CommentApp