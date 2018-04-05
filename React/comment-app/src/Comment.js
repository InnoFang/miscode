/**
 * Created by InnF on 2018/4/6.
 */

import React, {Component} from 'react'

class Comment extends Component {
    render() {
        return (
            <div className="comment">
                <div className="comment-user">
                    <span>{this.props.username} </span>:
                </div>
                <p>{this.props.content}</p>
            </div>
        )
    }
}

export default Comment