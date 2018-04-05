/**
 * Created by InnF on 2018/4/5.
 */

import React, {Component} from 'react'
import Comment from './Comment'

class CommentList extends Component {
    static defaultProps = {
        comments: []
    }

    render() {
        return (
            <div>
                {this.props.comments.map((comment, i) =>
                    <Comment {...comment} key={i}/>
                )}
            </div>
        )
    }
}

export default CommentList